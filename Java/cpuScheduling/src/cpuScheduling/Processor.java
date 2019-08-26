package cpuScheduling;
import java.util.Random;
import java.util.PriorityQueue;
import java.util.Queue;

public class Processor {
	private int lastTaskTime;
	private int computingPower;
	private Queue <Task.simpleTask> processorQueue;
	
	public int getComputingPower() { return computingPower; }
	public void setComputingPower(int computingPower) { this.computingPower = computingPower; }
	
	public int getLastTaskTime() { return lastTaskTime; }
	public void setLastTaskTime(int lastTaskTime) { this.lastTaskTime = lastTaskTime; }
	public void addToTaskTime(int timeAdded) { this.lastTaskTime += timeAdded; }
	
	public void addToProcQueue (Task.simpleTask task1) {
		processorQueue.add(task1);
	}

	public Processor() {
		setComputingPower(new Random().nextInt(3)+1);
		processorQueue = new PriorityQueue<>();
		setLastTaskTime(0);
	}
	
	public void ProcReset() {
		processorQueue.clear();
		setLastTaskTime(0);
	}

	
	public String toString() {
		String message = "Procesor jest w czasie " + lastTaskTime + " sekundy\n";
		return message;
	}
}
