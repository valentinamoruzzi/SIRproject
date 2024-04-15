##SIRproject
La directory [include](SIRproject/include) comprende tutti gli header file (.hpp), mentre la directory [src](SIRproject/src) contiene i rispettivi file sorgente. 
Nella directory [Test](SIRproject/Test) invece troviamo i doctest.
La translation unit principale è costituita da [main.cpp](SIRproject/main.cpp).  
Il file [sirmodel.cvg](SIRproject/sirmodel.cvg) è il file di configurazione di input. **L'ordine del file di configurazione deve essere rispettato**.
Di seguito si scrivono le opzioni accetabili:  
Output_type = S (standard output)/ F (file csv)/ P (grafica)  
Output_file = example_csv  
Beta = [0,1]  
Gamma = [0,1]  
Alpha = [0,1]  
Susc = (int)  
Inf = (int)  
Rec = (int)  
Duration = (int)  
Model = sirmodel / sirmodelextended  
Per la compilazione è presente una [Cmakelist.txt](SIRproject.txt). Per ulteriori informazioni consultare [SIRproject.pdf](SIRproject/SIRproject.pdf)

