package l2;

import java.net.*;

import l2.formatted_msg.CTRL;

import java.io.*;

public class TCPClient {
	public static void main(String args[]) {
		// arguments supply message and hostname
		// Check command line
		if (args.length < 2) {
			System.err.println("Usage : ");
			System.err.println("java TCPClient <Message> <server>");
			System.exit(1);
		}
		Socket s = null;
		ObjectOutputStream out = null;
		// ObjectInputStream in;
		int serverPort = 7896;
		formatted_msg msg;
		try {
			//System.out.println(args[0] + " " + args[1] + " " + "wow");
			System.out.println("starting a new client socket");
			s = new Socket(args[1], serverPort);
			out = new ObjectOutputStream(s.getOutputStream());
			ObjectInputStream in = new ObjectInputStream(s.getInputStream());
			System.out.println("subscribing as: " + args[0]);
			msg = new formatted_msg(args[0], "dummy");
			formatted_msg.CTRL ctrl = formatted_msg.CTRL.SETUP;
			msg.set_ctrl(ctrl);
			out.writeObject(msg);

			// testing loopback
			formatted_msg m2 = new formatted_msg(args[0], "it is LB");
			m2.set_ctrl(formatted_msg.CTRL.LOOPBACK);
			System.out.println("sending " + m2);
			out.writeObject(m2);
			
			//testing normal
			formatted_msg m3 = new formatted_msg("", "");
					m3 = formatted_msg.init(m3);
			out.writeObject(m3);

			new Thread(new Runnable() {
				public void run() {
					try {
						while (true) {
							formatted_msg serverMes = (formatted_msg) in.readObject();
							// in.wait();
							System.out.println("Received incide new thred: " + serverMes);
							Thread.sleep(50);
						}
					} catch (ClassNotFoundException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}).start();

			Thread.sleep(50);
		} catch (UnknownHostException e) {
			System.out.println("Socket:" + e.getMessage());
		} catch (EOFException e) {
			System.out.println("EOF:" + e.getMessage());
		} catch (IOException e) {
			System.out.println("readline1:" + e.getMessage());
		} catch (InterruptedException e) {
			System.out.println("readline3:" + e.getMessage());
		}
		// finally {if(s!=null)
		// try {s.close();}catch (IOException
		// e){System.out.println("close:"+e.getMessage());}

		/*
		 * 
		 * while(true){ try { //s.setKeepAlive(true); //out = new
		 * ObjectOutputStream(s.getOutputStream()); in = new ObjectInputStream(
		 * s.getInputStream()); msg = (formatted_msg) in.readObject();
		 * System.out.println("Received mmes: "+ msg) ; Thread.sleep (200);
		 * }catch (IOException e){
		 * //System.out.println("readline4:"+e.getMessage()); }catch
		 * (InterruptedException
		 * e){System.out.println("readline5:"+e.getMessage()); }catch
		 * (ClassNotFoundException e) { // TODO Auto-generated catch block
		 * e.printStackTrace(); }
		 * 
		 * }
		 */

	}
}
