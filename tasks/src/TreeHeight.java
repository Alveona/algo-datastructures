import java.util.ArrayList;
import java.util.List;

public class TreeHeight {
    /*
        I just realised there is no equivalent to C's static variables in function (for example,
        in recursive functions), there is only class static variables
     */
    //static int currentRoot = 0;
    static int rootOfTree;

    public static void main(String[] args)
    {
        int[] testTree = {6, 7, 3, 6, 6, 3, 1, 7, 3};
        countTreeHeight(testTree.length, testTree);
    }

    static int countTreeHeight(int numberOfNodes, int[] listOfParents)
    {

        List<ArrayList<Integer>> listOfChildren = transformListOfParentsToListOfChildren(numberOfNodes, listOfParents);
        recursiveHeightCounter(rootOfTree, listOfChildren);
        return 0;
    }
    static int recursiveHeightCounter(int rootIndex, List<ArrayList<Integer>> listOfChildren)
    {
        //static int currentRoot = 0; // read note in the beginning of file
        int height = 1;
        System.out.println("\nIteration:");
        for(Integer child : listOfChildren.get(rootIndex - 1))
        {
            System.out.println(child);
            height = Math.max(height, 1 + recursiveHeightCounter(child, listOfChildren));
            //recursiveHeightCounter(listOfChildren.get(child), listOfChildren);
        }
        System.out.format("Height is %d\n", height);
        //currentRoot++;
        return height;
    }
    static List<ArrayList<Integer>> transformListOfParentsToListOfChildren(int numberOfNodes, int [] listOfParents)
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

        int rootIndex = 0;
        for(int i = 0; i < numberOfNodes; i++)
        {
            if(listOfParents[i] - 1 != i)
                listOfChildren.get(listOfParents[i] - 1).add(i + 1);
            else
                rootIndex = i + 1;
        }
        System.out.format("Root is %d\n", rootIndex);
        for(int i = 0; i < numberOfNodes; i++)
        {
            System.out.format("%d - ", i + 1);
            for(int j = 0; j < listOfChildren.get(i).size(); j++)
            {
                System.out.format("%d ", listOfChildren.get(i).get(j));
            }
            System.out.println();
        }
        rootOfTree = rootIndex;
        return listOfChildren;
    }
}
