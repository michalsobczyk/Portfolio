package cpuScheduling;
import java.util.ArrayList;
import java.util.List;

public class Resource {
	
	public static List<Processor> res;
	
	public static int resourcesSize() { return res.size(); }
	
	public Resource() {
		res = new ArrayList<Processor>();
		addProcessor();
	}

	public int getProcessorPower(int numberOfProcessor) {
		return res.get(numberOfProcessor).getComputingPower();
	}
	
	public int getProcessorTime (int numberOfProcessor) {
		return res.get(numberOfProcessor).getLastTaskTime();
	}
	
	public void setProcessorTime (int numberOfProcessor, int lastTaskTime) {
		res.get(numberOfProcessor).setLastTaskTime(lastTaskTime);
	}
	
	public void addToProcessorQueue (Task.simpleTask task1, int proc) {
		res.get(proc).addToProcQueue(task1);
	}
	
	public void addProcessor() {
		Processor p1 = new Processor();
		res.add(p1);
	}
	
	public void resourcesReset() {
		for(int i = 0; i < res.size(); i++) { res.get(i).ProcReset(); }
	}
	
	
	
	public String toString () {
		String message = "Mamy " + resourcesSize() + " procesorów\n";
		for (int i = 0; i < resourcesSize(); i++) { message += res.get(i).toString(); }
		return message;
	}
	
}
