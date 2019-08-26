package cpuScheduling;


public class Scheduling {

	
	public static void resetAll(Task t1, Resource r1) {
		System.out.println("Wywo³ano funkcjê resetuj¹c¹ ustawienia!!!");
		r1.addProcessor();
		t1.taskReset();
		r1.resourcesReset();
	}
	

	
	public Scheduling () {
		Resource r1 = new Resource();
		Task t1 = new Task();
		
		System.out.println(r1);
		System.out.println(t1);
	
		boolean flag = true;
		int minTime = 0, usedProcessor = 0;
		int actTask, nextTask;
		int executionTime = 0;
		while (flag) {		

			minTime = r1.getProcessorTime(0);
			usedProcessor = 0;
			if (Resource.resourcesSize() > 1) {
				for (int i = 1; i < Resource.resourcesSize(); i++) {
					if (minTime > r1.getProcessorTime(i)) { minTime = r1.getProcessorTime(i); usedProcessor = i; }
					else if (minTime == r1.getProcessorTime(i)) { 
						if (r1.getProcessorPower(usedProcessor) < r1.getProcessorPower(i)) { usedProcessor = i; }
					}
				}
			}
			actTask = Task.bestPossibleTask(minTime);
			if (actTask > 1) { nextTask = Task.nextPossibleTask(actTask); }
			else if (actTask == -1) { nextTask = Task.nextPossibleTask(Task.getTasksSize()); }
			else { nextTask = 0; }
			try {
				if (actTask > 0) { 
					executionTime = t1.getStartTime(nextTask) - minTime;
					if (executionTime >= t1.getLeftTaskSize(actTask)) { 
						minTime+= t1.getLeftTaskSize(actTask); 
						t1.setLeftTaskSize(actTask, 0); 
						Task.checkDeadline(minTime, t1.getDeadline(actTask), actTask);
						t1.removeTask(actTask);
						nextTask--;
					}
					else { 
						minTime += executionTime; 
						t1.setLeftTaskSize(actTask, t1.getLeftTaskSize(actTask)-executionTime);
						Task.checkDeadline(minTime, t1.getDeadline(actTask), actTask);
					}
					r1.setProcessorTime(usedProcessor, minTime);
				}	// Dodawanie tasków do kolejki procesora zrób
				else if (actTask == 0) {
					minTime += t1.getLeftTaskSize(0);
					r1.setProcessorTime(usedProcessor, minTime);
					t1.setLeftTaskSize(actTask, 0);
					Task.checkDeadline(minTime, t1.getDeadline(actTask), actTask);
					t1.removeTask(actTask);
					nextTask--;
				}
				else {
					r1.setProcessorTime(usedProcessor, t1.getStartTime(nextTask));
				}
			}
			catch (TooLessResourcesException e) {
				System.out.println(e);
				resetAll(t1, r1);
				if (Resource.resourcesSize() > 9) {
					return;
				}
			}
			
			if (Task.getTasksSize() == 0) { System.out.println("Zadanie skoñczone\n\n-----------------------------------------------------------------------------------------------\n\n"); flag = false; }			
			System.out.println(r1);
			System.out.println(t1);
			System.out.println("\n-----------------------------------------------------------------------------------------------\n");
		}
	}

}
