package cpuScheduling;
import java.util.Random;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Task {

	public static int numberOfTasks = new Random().nextInt(10)+1;
	public static List<simpleTask> taskQueue;
	public static List<simpleTask> queueCopy;
	
	public class simpleTask implements Comparable<Task.simpleTask> {
		private int leftTaskSize;
		private int taskSize;
		private int startTime;
		private int deadline;
		
		public int getTaskSize() { return taskSize; }
		public void setTaskSize(int taskSize) { this.taskSize = taskSize; }
		
		public int getStartTime() { return startTime; }
		public void setStartTime(int startTime) { this.startTime = startTime; }
		
		public int getDeadline() { return deadline; }
		public void setDeadline(int deadline) { this.deadline = deadline; }
		
		public int getLeftTaskSize() { return leftTaskSize; }
		public void setLeftTaskSize(int val) { leftTaskSize = val; }
		public void minusLeftTaskSize(int val) { leftTaskSize -= val; }
		
		public void simpleReset () { this.setLeftTaskSize(getTaskSize()); }
		
		public int compareTo (Task.simpleTask t) {
			return t.taskSize - this.taskSize;
		}
		
		public simpleTask() {
			setStartTime(new Random().nextInt(15));
			setDeadline(new Random().nextInt(15)+15);
			setTaskSize(new Random().nextInt(this.getDeadline() - this.getStartTime()) + 1);
			setLeftTaskSize(getTaskSize());
		}
		
		public String toString() {
			String message = "Zadaniu zosta³o " + getLeftTaskSize() + " sekund, z " + getTaskSize() + " sekund. Start time zadania to " + getStartTime() + ", a deadline to " + getDeadline() + "\n";
			return message;
		}
	}
	

	
	class SortByRoll implements Comparator<simpleTask>{
		public int compare(simpleTask task1, simpleTask task2) {
			if (task1.taskSize < task2.taskSize) return 1;
			else if (task1.taskSize > task2.taskSize) return -1;
			else return 0;
		}
	}

	public simpleTask instantiate() {
		return new simpleTask();
	}
	
	public simpleTask getElement(int a) {
		return taskQueue.remove(a);
	}
	
	public List<simpleTask> getQueue () { return taskQueue; }
	
	public static int getTasksSize() { return taskQueue.size(); }
	
	public int getLeftTaskSize(int a) { return taskQueue.get(a).getLeftTaskSize(); }
	public void setLeftTaskSize(int a, int val) { taskQueue.get(a).setLeftTaskSize (val); }
	
	public int getTotalTaskSize(int a) { return taskQueue.get(a).getTaskSize(); }
	
	public int getDeadline(int a) { return taskQueue.get(a).getDeadline(); }
	public void setDeadline (int a, int val) { taskQueue.get(a).setDeadline(val); }
	
	/*public simpleTask getSimpleTask(int a) {
		return this.getTopElement(a);
	}*/
	
	public int getStartTime(int taskNumber) { return taskQueue.get(taskNumber).getStartTime(); }
	
	
	public Task () {
		taskQueue = new ArrayList<>();
		queueCopy = new ArrayList<>();
		for (int i = 0; i < numberOfTasks; i++) {
			Task.simpleTask e = this.new simpleTask();
			taskQueue.add(e);
			queueCopy.add(e);
		}
		Collections.sort(taskQueue, new SortByRoll());
		Collections.sort(queueCopy, new SortByRoll());
	}
	
	public void removeTask (int taskNumber) {
		taskQueue.remove(taskNumber);
	}
	
	public void taskReset() {
		taskQueue.clear();
		for (int i = 0; i < numberOfTasks; i++) {
			taskQueue.add(queueCopy.get(i));
			Collections.sort(taskQueue, new SortByRoll());
			taskQueue.get(i).setLeftTaskSize(taskQueue.get(i).getTaskSize());
		}
	}	
	
	public static int nextPossibleTask (int taskNumber) {
		int task = 0;
		for(int i = 1; i < taskNumber; i++) {
			if (taskQueue.get(task).getStartTime() > taskQueue.get(i).getStartTime()) {
				task = i;
			}
		}
		return task;
	}	
	
	public static int bestPossibleTask (int maxTime) {
		int minStartTime=taskQueue.get(0).getStartTime();
		if (taskQueue.size() > 1) {
			if (minStartTime > maxTime) {
				for (int i = 1; i < taskQueue.size(); i++) {
					if (taskQueue.get(i).getStartTime() <= maxTime) return i;
				}
			return -1;
			}
		}
		if (minStartTime > maxTime) return -1;
		return 0;
	}
	
	public static void checkDeadline (int actTime, int deadline, int task) throws TooLessResourcesException {
		if (actTime > deadline) {
			System.out.println("Sprawdzam deadline");
			throw new TooLessResourcesException(deadline, actTime, task);
		}
	}
	
	public String toString () {
		String message = "Mamy " + getTasksSize() + " zadañ\n";
		for (int i = 0; i < getTasksSize(); i++) { message += taskQueue.get(i).toString(); }
		return message;
	}
	

}
