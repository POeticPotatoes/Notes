/*
 * Name: Yang iiyu
 * Group: SCSD
 * IP Address: 10.96.187.224
 */
package me.poeticpotatoes.qotdtest;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

public class Rfc865UdpClient {
	private static final int port=17;
	private static final byte[] ping = new String("Yang Iiyu, SCSD, 10.96.187.244").getBytes();
	private static InetAddress address; 
	
	private static DatagramSocket socket;

	public static void main(String[] argv) throws UnknownHostException {
		//
		// 1. Open UDP socket
		//
		try {
			socket = new DatagramSocket();
			address = InetAddress.getByName("swlab2-c.scse.ntu.edu.sg");
		} catch (SocketException e) {
			e.printStackTrace();
		}

		try {
			//
			// 2. Send UDP request to server
			//
			DatagramPacket request = new DatagramPacket(ping, ping.length, address, port); 
			System.out.println("Pinging socket!");
			socket.send(request);
			//
			// 3. Receive UDP reply from server
			//
			byte[] buf = new byte[256];
			DatagramPacket reply = new DatagramPacket(buf, buf.length, address, port);
			socket.receive(reply);
			System.out.printf("Received Response!\n");
			String res = new String(reply.getData(), 0, reply.getLength());
			System.out.printf("Quote of the day: %s\n", res);
		} catch (IOException e) {}
	}
}