#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
struct person 
{ 
        int id; 
        char fname[20]; 
        float time;; 
}; 
int main(){ 
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66, 46, 51, 765, 665, 33, 7, 39};

        //int arr1[4];
	//int arr[] = {5,9,1,8,2,6,4,7,3};        
  	int n = sizeof(arr)/sizeof(arr[0]);
	int output[n]; 
        int count[sizeof(arr)/sizeof(arr[0])]={0}, i, j; 
	clock_t t,t3;
	t = clock();
	FILE *infile; 
	//struct person input; 

	//infile = fopen ("person.dat", "r"); 
	// read file contents till end of file 
	//while(
	// Moving pointer to end 
	//for (int i=3;i>=0;i--){
	//fseek(infile, sizeof(struct person)*i, 0); 
	//fread(&input, sizeof(struct person), 1, infile);
	//arr1[i]=input.id;
	//printf ("id = %d name = %s %s\n", input.id, input.fname, input.lname); 
	//}
	
	// close file 
	//fclose (infile); 

       FILE *logfile; 
               
       // open file for writing 
        logfile = fopen ("logfile", "w"); 
                if (logfile == NULL) 
                        { 
                    fprintf(stderr, "\nError opend file\n"); 
             exit (1); 
                  } 
            //struct person input1;
	    //= {1, "sec:", "sharma"}; 
             //struct person input2 = {2, "mahendra", "dhoni"}; 
             //struct person input3 = {3, "roh", "srma"}; 
            //struct person input4 = {4, "ndra", "dhi"};
            // write struct to file 
	     // for(int i=0;i<500000;i++){
	      //fwrite (&input1, sizeof(struct person), 1, outfile); 
	      //fwrite (&input2, sizeof(struct person), 1, outfile); 
	      //fwrite (&input3, sizeof(struct person), 1, outfile); 
	      //fwrite (&input4, sizeof(struct person), 1, outfile); 
	      // }
	                                                                                                                                                               
	      if(fwrite != 0) 
	      printf("contents to file written successfully !\n"); 
	      else
	      printf("error writing file !\n"); 
	      // close file 
	     //  fclose (outfile); 
	      
	for(i = n-1;i>=1; --i) 
	        for (j=i-1;j>=0;--j){
		        ++count[(arr[i] - arr[j]) > 0 ? i : j];
		t3=clock()-t; 
		if ((arr[i]-arr[j])>0){
		printf("%f %i - %i > 0", ((double)t3)/CLOCKS_PER_SEC, arr[i],arr[j]);

		for (int k = 0; k < n; ++k)
		printf(" %i",count[k]); 

		printf("  inversion, counting\n");
		}else{
		
		  printf("%f %i - %i < 0", ((double)t3)/CLOCKS_PER_SEC, arr[i],arr[j]);
		 for (int k = 0; k < n; ++k)
			         printf(" %i",count[k]);
		  printf("  not inversion\n");

		
		
		
		
		}
		//float tt=((double)t3)/CLOCKS_PER_SEC;
		//struct person input1 = {1, "sec: ", tt}; 
		//fwrite (&input1, sizeof(struct person), 1, logfile);
		}
	for (i = 0; i < n; ++i)
	output[count[i]] = arr[i]; 
	
	for (i=0;i<n;++i)
		printf("%i ", output[i]);
        printf("\n");
	//t3=clock()-t; 
	//printf("sec: %f", ((double)t3)/CLOCKS_PER_SEC);
	//printf("end\n");
	 // close file 
	            fclose (logfile); 
	                          
	                             
	return 0; 
} 
