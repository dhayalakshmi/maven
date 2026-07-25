//DHAYALAKSHMI
//24MIS0158.
import java.net.*; 
import java.io.*; 
class ChatServer{
public static void main(String[] args) throws Exception {
   ServerSocket ss = new ServerSocket(9000);
   Socket s = ss.accept();
   BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
   PrintWriter pw = new PrintWriter(s.getOutputStream(),true)
   BufferedReader user = new BufferedReader(new InputStreamReader(System.in));
   String msg;
   while((msg = br.readLine()) != null){
	    System.out.println("Client: "+msg); 
	    pw.println(user.readLine());
    }
   s.close();
   ss.close();
   }
}
