package lesson_1;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int hours = n / 3600;
        int minutes = (n % 3600) / 60;
        int seconds = n % 60;
        if (hours >= 24) {
            hours = hours % 24;
        }
        String ans = String.format("%d:%02d:%02d", hours, minutes, seconds);
        System.out.println(ans);
    }
}