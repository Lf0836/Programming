package lesson_2;
import java.util.Scanner;

public class lesson_2 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int x = scan.nextInt();
        int y = scan.nextInt();
        if ((x < y) && (x > 0) && (y > 0) && (x*x + y*y) > 4 && (y > 0)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
