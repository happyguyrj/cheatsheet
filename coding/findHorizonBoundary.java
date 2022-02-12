import java.util.*;

class BuildingEdge implements Comparable<BuildingEdge> {

    private int position;
    private boolean isStart;
    private int height;

    public BuildingEdge(int position, boolean isStart, int height) {
        this.position = position;
        this.isStart = isStart;
        this.height = height;
    }

    public int getPosition() {
        return position;
    }

    public void setPosition(int position) {
        this.position = position;
    }

    public boolean isStart() {
        return isStart;
    }

    public void setStart(boolean start) {
        isStart = start;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    @Override
    public int compareTo(BuildingEdge o) {
        int posDiff = this.position - o.position;
        if (posDiff != 0)
            return posDiff;
        return (this.isStart ? - this.height : this.height) - (o.isStart ? - o.height : o.height);
    }
}


class Building {

    private int start;
    private int end;
    private int height;

    public Building(int start, int end, int height) {
        this.start = start;
        this.end = end;
        this.height = height;
    }

    public int getStart() {
        return start;
    }

    public void setStart(int start) {
        this.start = start;
    }

    public int getEnd() {
        return end;
    }

    public void setEnd(int end) {
        this.end = end;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }
}


public class HelloWorld{

    public static void main(String[] args) {
		List<Building> buildings = new ArrayList<>();
		buildings.add(new Building(0,10,5));
		buildings.add(new Building(2,4,6));
		buildings.add(new Building(3,5,7));
		buildings.add(new Building(7,9,3));

		List<BuildingEdge> buildingEdges = new ArrayList<>();
		buildings.forEach(e -> {
			buildingEdges.add(new BuildingEdge(e.getStart(), true, e.getHeight()));
			buildingEdges.add(new BuildingEdge(e.getEnd(), false, e.getHeight()));
		});

		Collections.sort(buildingEdges);
		drawHorizon(buildingEdges);
	}

	public static void drawHorizon(List<BuildingEdge> buildingEdges) {
		Map<Integer, Integer> shadow = new LinkedHashMap<>();
		PriorityQueue<Integer> maxHeightQueue = new PriorityQueue<>(Collections.reverseOrder());
		maxHeightQueue.add(0);
		int preHeight = 0;
		int prePosition=0;

		for (BuildingEdge buildingEdge : buildingEdges) {
			if (buildingEdge.isStart()) {
				maxHeightQueue.add(buildingEdge.getHeight());
			}
			else {
				maxHeightQueue.remove(buildingEdge.getHeight());
			}

			int maxHeight = maxHeightQueue.peek();
			for (int i = prePosition; i<buildingEdge.getPosition(); i++) {
				shadow.put(i, preHeight);
			}

			shadow.put(buildingEdge.getPosition(), maxHeight);

			preHeight = maxHeight;
			prePosition = buildingEdge.getPosition();
		}

		for (Integer position: shadow.keySet()) {
			System.out.println(position + " " + shadow.get(position));
		}
	}
}