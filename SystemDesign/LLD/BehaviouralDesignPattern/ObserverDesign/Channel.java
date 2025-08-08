import java.util.ArrayList;
import java.util.List;

public class Channel implements IChannel {
  private List<Subscriber> subscribers =
      new ArrayList<>(); // List of subscribers
  private String name; // Name of the channel
  private String video; // The video that will be uploaded

  public Channel(String name) {
    this.name = name; // Initialize the channel with its name
  }

  @Override
  public String getName() {
    return name; // Return the name of the channel
  }

  @Override
  public void addSubscriber(Subscriber subscriber) {
    subscribers.add(subscriber); // Add a subscriber to the channel
  }

  @Override
  public void removeSubscriber(Subscriber subscriber) {
    subscribers.remove(subscriber); // Remove a subscriber from the channel
  }

  @Override
  public void notifySubscribers() {
    // Notify all subscribers about the new video
    for (Subscriber subscriber : subscribers) {
      subscriber.update(video); // Call update() for each subscriber
    }
  }

  public void uploadNewVideo(String video) {
    this.video = video; // Set the video that is being uploaded
    notifySubscribers(); // Notify all subscribers about the new video
  }
}
