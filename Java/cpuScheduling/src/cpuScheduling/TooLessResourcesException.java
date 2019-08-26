package cpuScheduling;

class TooLessResourcesException extends Exception {
	
	private String message;
	
	public TooLessResourcesException(int deadline, int actTime, int zadanie) {
		this.message = "Maksymalny deadline dla zadania " + zadanie + " to " + deadline + ", a osiagnelismy " + actTime + ". Jezeli nie ma wiêcej ni¿ 10 procesorow, to dodam nowy";
	}
	
	public String toString () {
		return message;
	}
	
	public String getMessage() {
		return message;
	}

}
