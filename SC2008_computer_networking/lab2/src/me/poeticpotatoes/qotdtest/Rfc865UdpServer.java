package me.poeticpotatoes.qotdtest;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class Rfc865UdpServer {
	static DatagramSocket socket;
	static final byte[] quote = new String("Workers of the world, arise! You have nothing to lose but your chairs.").getBytes();
	static final int port=25565;

	public static void main(String[] argv) {
		//
		// 1. Open UDP socket at well-known port
		//
		try {
			socket = new DatagramSocket(port);
		} catch (SocketException e) {
			e.printStackTrace();
			return;
		}

		while (true) {
			try {
				//
				// 2. Listen for UDP request from client
				//
				byte[] buf = new byte[256];
				DatagramPacket request = new DatagramPacket(buf, buf.length); 
				System.out.printf("Listening on port %d\n", port);
				socket.receive(request);

				InetAddress address = request.getAddress();
				int senderPort = request.getPort();
				String val = new String(request.getData(), 0, request.getLength());
				System.out.printf("Received request: %s\n Sending reply...", val);
				//
				// 3. Send UDP reply to client
				//
				DatagramPacket reply = new DatagramPacket(quote, quote.length, address, senderPort); 
				socket.send(reply);
				System.out.println("Reply sent!");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
