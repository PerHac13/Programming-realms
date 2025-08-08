public class Main {
    public static void main(String[] args) {
        
        Channel YouTubeChannel = new Channel("YT");

        // Create subscribers
        Subscriber subscriber1 = new YouTubeSubscriber("Alice");
        Subscriber subscriber2 = new YouTubeSubscriber("Bob");
        Subscriber subscriber3 = new PushNotificationSubscriber("Device1");
        Subscriber subscriber4 = new EmailSubscriber("example@gmail.com");

        YouTubeChannel.addSubscriber(subscriber1);
        YouTubeChannel.addSubscriber(subscriber2);
        YouTubeChannel.addSubscriber(subscriber3);
        YouTubeChannel.addSubscriber(subscriber4);

        // Upload a new video
        YouTubeChannel.uploadNewVideo("Observer Design Pattern in Java");

        // Remove a subscriber
        YouTubeChannel.removeSubscriber(subscriber2);
        // Upload another video
        YouTubeChannel.uploadNewVideo("Understanding Observer Pattern");

    }
}
