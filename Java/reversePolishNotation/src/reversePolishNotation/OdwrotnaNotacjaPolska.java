package reversePolishNotation;
import java.util.Scanner;


public class OdwrotnaNotacjaPolska {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*Scanner input = new Scanner (System.in);
		String wyrazenie = input.nextLine();
		Stos styrta = new Stos (wyrazenie);
		Stos znaki = new Stos (null);
		String wyjscie = new String();
		String e = styrta.getZnak();
		while (styrta.getTop() != '=') {
			if (e == "(") styrta.addToStack(e);
			else if (e == ")") {
				while (styrta.getTop() != '(') {
					wyjscie = wyjscie + styrta.getZnak();
				}
			}
		}*/
		Stos styrta = new Stos(" 22 + 2225 =");
		System.out.println(styrta.getStack() + " " + styrta.getLength());
		System.out.println(styrta.getZnak());
		System.out.println(styrta.getStack() + " " + styrta.getLength());
		System.out.println(styrta.getZnak());
		System.out.println(styrta.getStack() + " " + styrta.getLength());
		System.out.println(styrta.getZnak());
		System.out.println(styrta.getStack() + " " + styrta.getLength());
		System.out.println(styrta.getZnak());
		System.out.println(styrta.getStack() + " " + styrta.getLength());
		styrta.addToStack("5+");
		styrta.addToStack("2+");
		System.out.println(styrta.getStack());
		
	}
}
