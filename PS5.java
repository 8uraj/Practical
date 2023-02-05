import java.util.Random;

class FirstThread extends Thread {
    public void run() {
        Random rand = new Random();
        while (true) {
            int num = rand.nextInt(100);
            System.out.println("Generated number: " + num);
            if (num % 2 == 0) {
                SecondThread second = new SecondThread(num);
                second.start();
            } else {
                ThirdThread third = new ThirdThread(num);
                third.start();
            }
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("First thread interrupted.");
            }
        }
    }
}

class SecondThread extends Thread {
    int num;

    SecondThread(int num) {
        this.num = num;
    }

    public void run() {
        System.out.println("Square of " + num + " is: " + (num * num));
    }
}

class ThirdThread extends Thread {
    int num;

    ThirdThread(int num) {
        this.num = num;
    }

    public void run() {
        System.out.println("Cube of " + num + " is: " + (num * num * num));
    }

    public static void main(String[] args) {
        FirstThread first = new FirstThread();
        first.start();
    }
}
