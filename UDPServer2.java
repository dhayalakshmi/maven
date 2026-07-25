import java.net.*;
public class UDPServer2 {
    public static void main(String args[]) throws Exception {
        DatagramSocket serverSocket =new DatagramSocket(9876);
        byte[] receiveData = new byte[1024];
        byte[] sendData;
        while(true) {
            DatagramPacket receivePacket =new DatagramPacket(receiveData, receiveData.length);
            serverSocket.receive(receivePacket);
            String num =new String(receivePacket.getData(), 0, receivePacket.getLength());
            String result = "";
            for(int i = 0; i < num.length(); i++) {
                char c = num.charAt(i);
                int digit = c - '0';
                digit = digit + 1;
                result = result + digit;
            }
            sendData = result.getBytes();
            InetAddress IPAddress =receivePacket.getAddress();
            int port =
                receivePacket.getPort();
            DatagramPacket sendPacket =
                new DatagramPacket(sendData, sendData.length, IPAddress, port);
            serverSocket.send(sendPacket);
        }
    }
}
//dhaya lakshmi A
//24MIS0158


C:\Users\Admin\AppData\Local\Programs\Microsoft VS Code