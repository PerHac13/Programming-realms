package SystemDesign.LLD.BehaviouralDesignPattern.MediatorDesign;

public interface AuctionMediator {
  void registerBidder(Bidder bidder);
  void placeBid(Bidder bidder, int amount);
}