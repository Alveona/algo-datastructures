import java.util.ArrayList;
import java.util.List;

public class TreeHeight {
    public static void main(String[] args)
    {
        int[] testTree = {6, 7, 3, 6, 6, 3, 1, 7, 3};
        countTreeHeight(testTree.length, testTree);
    }

    static int countTreeHeight(int numberOfNodes, int[] listOfParents)
    {
        transformListOfParentsToListOfChildren(numberOfNodes, listOfParents);
        return 0;
    }

    static void transformListOfParentsToListOfChildren(int numberOfNodes, int [] listOfParents)
    {
        List<ArrayList<Integer>> listOfChildren = new ArrayList<>();
        System.out.println("List of parents:");
        for(int i = 0; i < numberOfNodes; i++)
        {
            System.out.format("%d ", i+1);
        }
        System.out.println();
        for(int i = 0; i < numberOfNodes; i++)
        {
            System.out.format("%d ", listOfParents[i]);
        }


        System.out.println("\nList of children: ");
        for(int i = 0; i < numberOfNodes; i++)
        {
            listOfChildren.add(i, new ArrayList<Integer>());
        }
        for(int i = 0; i < numberOfNodes; i++)
        {
            listOfChildren.get(listOfParents[i] - 1).add(i);
        }
        for(int i = 0; i < numberOfNodes; i++)
        {
            System.out.format("%d - ", i + 1);
            for(int j = 0; j < listOfChildren.get(i).size(); j++)
            {
                System.out.format("%d ", listOfChildren.get(i).get(j) + 1);
            }
            System.out.println();
        }
    }
}
