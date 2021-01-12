public class mergeArrays{
    public static void main(String[] args){
        int[] arr_1 = {0, 2, 2};
        int[] arr_2 = {1, 3};
        int[] C = merge(arr_1, arr_2);
        print_arr(C);
    }

    public static int[] merge(int[] a1, int[] a2){
        int a1_size = a1.length;
        int a2_size = a2.length;
        int[] res = new int[a1_size + a2_size];
        int i = 0;
        int j = 0;
        int k = 0;   
        while (i < a1_size || j < a2_size){
            if (j == a2_size || (i < a1_size && a1[i] < a2[j])){
                 System.out.println("Ввод " + a1[i] + " эллемента в ячейку "+ k);
               res[k++] = a1[i++];
            }
            else{
                  System.out.println("Ввод " + a2[j] + " эллемента в ячейку "+ k);
               res[k++] = a2[j++];
            }
        }
        return res;
    }

    public static void print_arr(int[] A){
        for(int i = 0; i < A.length; i++){
            System.out.print(A[i]);
        }
        System.out.println();
    }
}
