package l2;

import java.net.*;

import l2.formatted_msg.CTRL;

import java.io.*;

public class TCPClient {
	public static void main(String args[]) {
		// arguments supply message and host name
		// Check command line
		if (args.length < 2) {
			System.err.println("Usage : ");
			System.err.println("java TCPClient <Message> <server>");
			System.exit(1);
		}
		Socket s = null;
		int serverPort = 7896;
		formatted_msg msg;
		// set up initial connection
		try {
			System.out.println("starting a new client socket");
			s = new Socket(args[1], serverPort);
			ObjectOutputStream out = new ObjectOutputStream(s.getOutputStream());
			ObjectInputStream in = new ObjectInputStream(s.getInputStream());
			System.out.println("subscribing as: " + args[0]);
			msg = new formatted_msg(args[0], "dummy");
			formatted_msg.CTRL ctrl = formatted_msg.CTRL.SETUP;
			msg.set_ctrl(ctrl);
			out.writeObject(msg);

			// loopback testing connection
			formatted_msg m2 = new formatted_msg(args[0], "it is LB");
			m2.set_ctrl(formatted_msg.CTRL.LOOPBACK);
			System.out.println("sending " + m2);
			out.writeObject(m2);
			formatted_msg sMes;
			try {
				sMes = (formatted_msg) in.readObject();
				System.out.println("Loopback is recived: " + sMes);
			} catch (ClassNotFoundException e1) {
				e1.printStackTrace();
			}

			// testing all type of connections
			// create terminate meassage to close it and exit from this client

							formatted_msg m3 = new formatted_msg("", "");
							m3 = formatted_msg.init(m3);
							out.writeObject(m3);
							
			//starting listening for server					
			new Thread(new Runnable() {
				public void run() {
					try {
						while (true) {
							formatted_msg serverMes = (formatted_msg) in.readObject();
							System.out.println("Received measage: " + serverMes);
							Thread.sleep(50);
						}
					} catch (ClassNotFoundException e) {

					} catch (IOException e) {

					} catch (InterruptedException e) {

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
		} finally {
			if (s != null)
				try {
					s.close();
				} catch (IOException e) {
					System.out.println("close:" + e.getMessage());
				}
		}
	}
}
