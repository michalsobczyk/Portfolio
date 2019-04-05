package reversePolishNotation;
import java.util.Scanner;


public class OdwrotnaNotacjaPolska {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner (System.in);
		String wyrazenie = scanner.nextLine();
		Stos styrta = new Stos (wyrazenie);
		Stos znaki = new Stos ("+");
		znaki.getZnak();
		String wyjscie = new String();
		String e = new String();
		while (styrta.getTop() != '=') {
			e = styrta.getZnak();
			if (e == "(") znaki.addToStack(e);
			else if (e == ")") {
				while (znaki.getTop() != '(') wyjscie = wyjscie + znaki.getZnak();
				e = znaki.getZnak();
			}
			else if (!Character.isDigit(e.charAt(0))) {
				int prio = 0;
				if (e.charAt(0) == '+' || e.charAt(0) == '-') prio = 1;
				else if (e.charAt(0) == '*' || e.charAt(0) == '/') prio = 2;
				else if (e.charAt(0) == '^') prio = 3;
				while (!znaki.isEmpty()) {
					if (prio != 3 || prio <= znaki.prioTop()) wyjscie = wyjscie + znaki.getZnak();
					else {
						znaki.addToStack(e);
						break;
					}
				}
			}
			else wyjscie = wyjscie + e;
		}
		System.out.println(wyjscie);
		scanner.close();
		/*Stos styrta = new Stos(" 22 + 2225 =");
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
		System.out.println(styrta.getStack());*/
		
	}
}
