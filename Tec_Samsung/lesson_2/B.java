package lesson_2;

import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        float x = scanner.nextFloat();
        float y = scanner.nextFloat();
        if ((y < 0.5) && (y > 0)
                && (y < Math.sin(x))
                && (x > 0) && (x < Math.PI)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
