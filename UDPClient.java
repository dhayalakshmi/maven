import java.net.*;
import java.io.*;
public class UDPClient {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        DatagramSocket clientSocket = new DatagramSocket();
        InetAddress IPAddress =InetAddress.getByName("localhost");
        byte[] sendData;
        byte[] receiveData = new byte[1024];
        System.out.print("Enter 4 digit number: ");
        String num = br.readLine();
        sendData = num.getBytes();
        DatagramPacket sendPacket =new DatagramPacket(sendData, sendData.length, IPAddress, 9876);
        clientSocket.send(sendPacket);
        DatagramPacket receivePacket =
            new DatagramPacket(receiveData, receiveData.length);
        clientSocket.receive(receivePacket);
        String result =
            new String(receivePacket.getData(), 0, receivePacket.getLength());
        System.out.println("Result: " + result);
        clientSocket.close();
    }
}
