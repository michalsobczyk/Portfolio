package reversePolishNotation;

public class Stos {
	private String stack;
	
	public Stos (String znaki){
		stack = new String (znaki);
	}
	
	public String getZnak () {
		String temp = new String();
		for(int i = 0; i < stack.length(); i++) {
			if (stack.charAt(i) == ' ') continue;
			else if (stack.charAt(i) == '+' || stack.charAt(i) == '-' || stack.charAt(i) == '*' || stack.charAt(i) == '/' || stack.charAt(i) == '=' || stack.charAt(i) == '(' || stack.charAt(i) == ')') {
				temp = Character.toString(stack.charAt(i));
				stack = stack.substring (i+1);
				return temp;
			}
			else if (Character.isDigit(stack.charAt(i))){
				temp += stack.charAt(i);
				for(int j = i+1; j < stack.length(); j++) {
					if (Character.isDigit(stack.charAt(j))) temp += Character.toString(stack.charAt(j));
					else {
							stack = stack.substring (j);
							return temp;
					}
				}
			}
		}
		return temp;
	}
	
	public char getTop () {
		int counter = 0;
		for (int i = 0; i < stack.length(); i++) {
			if(stack.charAt(i) == ' ') continue;
			else {
				return stack.charAt(counter);
			}
		}
	return 0;
	}
	
	public void removeTop () {
		for(int i = 0; i < stack.length(); i++) {
			
		}
	}
	
	public int getLength() {
		int counter = 0;
		for (int i = 0; i < stack.length(); i++) {
			if (stack.charAt(i) == ' ') continue;
			else if (stack.charAt(i) == '+' || stack.charAt(i) == '-' || stack.charAt(i) == '*' || stack.charAt(i) == '/' || stack.charAt(i) == '=' || stack.charAt(i) == '(' || stack.charAt(i) == ')') counter++;
			else if (Character.isDigit(stack.charAt(i))) {
				counter++;
				for (int j = i+1; j < stack.length(); j++) {
					if (Character.isDigit(stack.charAt(j))) continue;
					else {
						i = j-1;
						break;
					}
				}
			}
		}
		return counter;
	}
	
	public int prioTop() {
		if (stack.charAt(0) == '+' || stack.charAt(0) == '-') return 1;
		else if (stack.charAt(0) == '*' || stack.charAt(0) == '/') return 2;
		else if (stack.charAt(0) == '^') return 3;
		else return 0;
	}
	
	public boolean isEmpty() {
		if (stack.length() == 0) return true;
		else return false;
	}
	
	public String getStack() {
		return stack;
	}
	
	public void addToStack(String character) {
		stack = character + stack;
	}
	/*public String redukcjaStosuPrzod () {
		for(int i = 0; i < stack.length(); i++) {
			if (stack.charAt(i) == )
		}
	}*/
}
