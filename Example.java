//
//  Code to generate hashcodes from strings 
//  used to identify seeds for minecraft
//
//  @phaktor
//  @nopesled 
//
//  run: java  Example.java | sort -n 
//
                                                                  
import java.io.*;                                                 
import java.io.FileInputStream;                                   
import java.io.FileNotFoundException;  
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

import java.io.IOException;



public class Example {
        public static void main(String[] args) throws IOException {
                // Declaring and initializing the string with
                // custom path of a file
//                 String path = "words";
                String path = "/usr/share/dict/american-english";
         
                // Creating an instance of Inputstream
                InputStream is = new FileInputStream(path);
         
                // Try block to check for exceptions
                try (Scanner sc = new Scanner(
                         is, StandardCharsets.UTF_8.name())) {
         
                    // It holds true till there is single element
                    // left in the object with usage of hasNext()
                    // method
                    while (sc.hasNextLine()) {
         
                        // Printing the content of file

                                String seed = "S41NTC0N ";
                                seed = seed.concat(sc.nextLine());
                                seed = seed.trim();
                               System.out.println(seed.hashCode()+" : "+seed);
                        }
                }
        }
}
