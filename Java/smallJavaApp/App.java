
/* 
prog1 
st1
*/

import java.util.Scanner;

public class App {
    public static void main(String[] args) {

        int a = 0;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your word: ");
        String wrd = scanner.nextLine();
        System.out.print("Enter your number: ");
        int b = scanner.nextInt();
        System.out.println("Word: " + wrd); //word1
        System.out.println("meaning1: " + wrd + "?");

        // integer
        a = 22;
        if(!(b<0)) {
        //int b = a % 3;
        System.out.println(b);
            }
        else if((b<=-1) && (b>-4)) {
        System.out.println("-1-2");
            }
        else {

            }

        switch (b) {
            case (1):
                System.out.println("b = 1");
                break;
            case (2):
                System.out.println("b = 2");
                break;
            case (3):
                System.out.println("b = 3");
                break;
            default:
                System.out.println("another number");
                break;
                }

        int c = 2;
        while (c<10) {
            System.out.println("c=" + c);
            c*=2;
            }

        System.out.println("Arrays");
        for(int d=0;d<5;d++) {
            if (d==2) {
                continue;
                }
            System.out.println(d);
            }

        System.out.println("for loop");
        int[] ages = new int[5];
        String[] letters = {"a","b"};
        ages[2] = 1;
        System.out.println("ages2=" + ages[2] + letters[0]);

        for(int arrIndex = 0;arrIndex<letters.length;arrIndex++) {
            System.out.println(letters[arrIndex]);
            }
    }
}
