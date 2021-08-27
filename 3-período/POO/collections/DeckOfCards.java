import java.util.List;
import java.util.Arrays;
import java.util.Collections;

class Card {

	public enum Face { Ace, Deuce, Three, Four, Five, Six, 
		Seven, Eight, Nine, Ten, Jack, Queen, King }
	public enum Suit { Clubs, Diamonds, Hearts, Spades }

	private final Face face;
	private final Suit suit;

	public Card(Face face, Suit suit) {
		this.face = face;
		this.suit = suit;
	}

	public Face getFace() { return this.face; }
	public Suit getSuit() { return this.suit; }

	public String toString() {
		return String.format("%s of %s", this.getFace(), this.getSuit());
	}

}

public class DeckOfCards {

	private List<Card> list;

	public DeckOfCards() {

		Card[] deck = new Card[52];
		int count = 0;

		for (Card.Suit suit : Card.Suit.values()) {
			for (Card.Face face : Card.Face.values()) {
				deck[count] = new Card(face, suit);
				++count;
			}
		}

		list = Arrays.asList(deck);
		Collections.shuffle(list);

	}

	public void printCards() {

		for (int i = 0; i < list.size(); i++) {
			System.out.printf("%-19s%s", list.get(i), 
					((i + 1) % 4 == 0) ? System.lineSeparator() : "");
		}

	}

	public static void main(String[] args) {

		DeckOfCards cards = new DeckOfCards();
		cards.printCards();

	}

}
