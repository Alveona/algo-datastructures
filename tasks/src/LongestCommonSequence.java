import java.lang.reflect.Array;
import java.util.ArrayList;

public class LongestCommonSequence {
    public static void main(String[] args) {
        assert(lcs("ABBA", "CABA")).equals("ABA");
        assert(lcs("ABCDEFG", "DEFGABCD")).equals("DEFG");
        assert(lcs("ABCDHGFTEFG", "DEFGDHGFTABCD")).equals("DHGFT");
    }

    private static String lcs(String sq1, String sq2) {
        int sq1_l = sq1.length();
        int sq2_l = sq2.length();
        int[][] matrix = new int[sq1_l + 1][sq2_l + 1];
        for (int i = sq1_l - 1; i >= 0; i--) {
            for (int j = sq2_l - 1; j >= 0; j--) {
                if (sq1.charAt(i) == sq2.charAt(j)) {
                    matrix[i][j] = matrix[i + 1][j + 1] + 1;
                } else {
                    matrix[i][j] = Math.max(matrix[i + 1][j], matrix[i][j + 1]);
                }
                System.out.format("%d ", matrix[i][j]);
            }
            System.out.println();
        }

        String lcs = "";
        int i = 0, j = 0;
        while (i < sq1_l && j < sq2_l) {
            if (sq1.charAt(i) == sq2.charAt(j)) {
                lcs += sq1.charAt(i);
                i++;
                j++;
            } else {
                if (matrix[i + 1][j] >= matrix[i][j + 1]) i++;
                else {
                    j++;
                }
            }
        }
        System.out.println(lcs);
        return lcs;
    }
}
