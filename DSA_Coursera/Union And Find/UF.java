import java.util.*;

 class QuickFindUF
{
    private int[] id;

    public QuickFindUF(int N){
        id= new int[N];
        for(int i=0;i<N;++i){
            id[i] = i;
        }
    }

    public boolean connected(int p, int q){
        return id[p] == id[q];
    }

    
};

public class UF
{
    public static void main(String[] args)
{
    Scanner IO= new Scanner(System.in);
    int N = IO.nextInt();
    QuickFindUF uf = new QuickFindUF(N);

    while(IO.hasNextInt()){
        int p = IO.nextInt();
        int q = IO.nextInt();
        if(uf.connected(p,q)) continue;
        // uf.union(p,q);
        System.out.println(p + " " + q);
    }
}
}





