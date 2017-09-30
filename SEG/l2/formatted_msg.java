package l2;

import java.io.*;
import java.util.Scanner;

public class formatted_msg implements Serializable {
	public enum CTRL {
		NORMAL, TERMINATE, LOOPBACK, BROADCAST, SETUP, GET_ALL_CLIENTS
	};

	String dest;
	String msg;
	CTRL msg_ctrl;

	public formatted_msg(String dst, String msg) {
		this.msg = msg;
		dest = dst;
		msg_ctrl = CTRL.NORMAL;
	}

	public void set_terminate() {
		msg_ctrl = CTRL.TERMINATE;
	}

	public void set_loopback() {
		msg_ctrl = CTRL.LOOPBACK;
	}

	public void set_ctrl(CTRL ctrl) {
		msg_ctrl = ctrl;
	}

	public CTRL get_ctrl() {
		return msg_ctrl;
	}

	public String get_dest() {
		return dest;
	}

	public void set_dest(String s) {
		this.dest = s;
	}

	public void set_msg(String s) {
		this.msg = s;
	}

	public String toString() {
		String str = "formatted_msg to " + dest + " msg: " + msg;
		switch (msg_ctrl) {
		case NORMAL:
			str += " NORMAL";
			break;
		case TERMINATE:
			str += " TERMINATE";
			break;
		case LOOPBACK:
			str += " LOOPBACK";
			break;
		case BROADCAST:
			str += " BROADCAST";
			break;
		case SETUP:
			str += " SETUP";
			break;
		case GET_ALL_CLIENTS:
			str += " GET_ALL_CLIENTS";
			break;
		}
		return str;
	}

	// Ask the user for the message type, destination, and content
	static formatted_msg init(formatted_msg msg) {

		Scanner s = new Scanner(System.in);
		CTRL mode = null;
		String des = "";
		String cont = "";
		while (mode == null) {
			System.out.println("Set Msg Type: ");
			String type = s.nextLine();
			switch (type) {
			case "NORMAL":
				mode = CTRL.NORMAL;
				System.out.println("Destination: ");
				des = s.nextLine();
				System.out.println("Content");
				cont = s.nextLine();
				break;
			case "TERMINATE":
				mode = CTRL.TERMINATE;
				break;
			case "LOOPBACK":
				mode = CTRL.LOOPBACK;
				break;
			case "BROADCAST":
				mode = CTRL.BROADCAST;
				System.out.println("Content");
				cont = s.nextLine();
				break;
			case "SETUP":
				mode = CTRL.SETUP;
				break;
			case "GET_ALL_CLIENTS":
				mode = CTRL.GET_ALL_CLIENTS;
				break;
			}
		}
		msg.set_dest(des);
		msg.set_msg(cont);
		msg.set_ctrl(mode);
		return msg;
	}

}
