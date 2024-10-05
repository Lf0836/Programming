package lesson_2;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner Scanner = new Scanner(System.in);
        float x = Scanner.nextFloat();
        float y = Scanner.nextFloat();
        if ((x > y) && (x > 0) && (y > 0) && (x*x + y*y) > 4 && (x < 2)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
