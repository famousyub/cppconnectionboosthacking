

import java.io.*;
import java.net.URI;
import java.net.http.*;

public class Fetching {
    public static void main(String [] args)  throws IOException, InterruptedException{


        HttpClient client  =  HttpClient.newHttpClient();

        HttpRequest request =  HttpRequest.newBuilder()
        .uri(URI.create("http://webcode.me"))
        .GET()
        .build();
        HttpResponse<Void> response   =client.send(request, 
        HttpResponse.BodyHandlers.discarding()
        );
        System.out.println(response.statusCode());
        System.out.println(response.body());


    }
}
