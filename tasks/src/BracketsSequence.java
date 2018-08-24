import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class BracketsSequence {


    public static void main(String[] args) {
        int code = isStringBracketsFine("\"{{{[][][]\"");
        System.out.println("\nTest done with code " + code);
        runTests();
    }

    static int isStringBracketsFine(String sequence) {
        Stack<Character> bracketsStack = new Stack<>();
        Stack<Integer> numberOfBracketStack = new Stack<>();
        int currentOpeningBracketIndex = 0;
        char[] charSequence = sequence.toCharArray();
        char[] validOpeningBrackets = {'{', '[', '('};
        List<Character> validCharacters = Arrays.asList('{', '[', '(', '}', ']', ')');
        int currentAnyBracketIndex = 0;
        char topBracket;
        for (Character symbol : charSequence) {
            if(!validCharacters.contains(symbol))
                continue;
            currentAnyBracketIndex++;
            if (symbol == validOpeningBrackets[0] || symbol == validOpeningBrackets[1] || symbol == validOpeningBrackets[2])
            {
                bracketsStack.push(symbol);
                currentOpeningBracketIndex++;
                numberOfBracketStack.push(currentOpeningBracketIndex);
            }
            else
            {
                if(bracketsStack.isEmpty()) return currentAnyBracketIndex;
                topBracket = bracketsStack.pop();
                numberOfBracketStack.pop();
                if(topBracket == '{' && symbol != '}'
                        || topBracket == '[' && symbol != ']'
                        || topBracket == '(' && symbol != ')')
                {
                    return currentAnyBracketIndex;
                }
            }
                System.out.println(bracketsStack);
        }
        if(bracketsStack.isEmpty())
            return 0;
        else
            return currentOpeningBracketIndex;
    }

    static void runTests()
    {
        assert isStringBracketsFine("([](){([])})") == 0;
        assert isStringBracketsFine("()[]}") == 5;
        assert isStringBracketsFine("{{[()]]") == 7;
        assert isStringBracketsFine("{{{[][][]") == 3;
        assert isStringBracketsFine("{*{{}") == 3;
        assert isStringBracketsFine("[[*") == 2;
        assert isStringBracketsFine("{*}") == 0;
        assert isStringBracketsFine("{{") == 2;
        assert isStringBracketsFine("{}") == 0;
        assert isStringBracketsFine("") == 0;
        assert isStringBracketsFine("}") == 1;
        assert isStringBracketsFine("*{}") == 0;
        assert isStringBracketsFine("{{{**[][][]") == 3;
    }

}
