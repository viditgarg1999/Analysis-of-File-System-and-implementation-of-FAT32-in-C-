# Analysis-of-File-System-and-implementation-of-FAT32-in-C++
Implementation of FAT32 File System in C++, and a project report on analysis of different File Systems.

## Further Reading
In this project, I have implemented FAT32 File System in C++. You just need to copy the code written in FileSystem.cpp file 
in any of your IDE(Code Blocks, Geany ,Dev C++ etc). Don't choose Turbo C++ because the program is not compatible with it and it may show Error.

In my File System implementation there are 9 different modules,

![](/images/Capture1.JPG)

  **1.Create a File :** In this module, the user need to Enter the Filename, Filesize and FileType.As we are implementing FAT32 so the file size should be less than 4GB(4096 MB) otherwise it will display an error message "Can not handle file of size greater then 4GB".Two files with same name can exist in the FileSystem but they should have different FileTypes otherwise it will display an error message.

![](/images/Capture2.JPG)
 
 **2.Delete a File:** In this module, the user need to Enter the filename and if file exists with the same it it will delete it and it more than one file exists with the same name then it will ask for filetype for more clerance and then it will delete it.
 
 ![](/images/Capture3.JPG)
 
 **3.Defragmentation:** In this module, The FileSystem is going to traverse the Starting Address and File Size of all the files and remove all the unallocated memory(which may occure because of File Deletion). Thus it helps in making the maximum use of the available memory.
 
 ![](/images/Capture4.JPG)
 
 **4.Display the Applicaiton Files:** It will display all the available files in the System.
 
 ![](/images/Capture5.JPG)
 
 **5.System Files Creation:** In this module, the user can create System Files which cannot be deleted and in order to see these files the user need to Enter a password.
 
 ![](/images/Capture6.JPG)
 
 **6.Display System Files:** First the user have to Enter the choice [y/n] and then it will ask for password (here the password is "admin"), Once the password got verified it will diaplay all the System Files.
 
 ![](/images/Capture7.JPG)
 
 **7.Search For a file:** The client can search for an Application File through this module.
 
 ![](/images/Capture8.JPG)
 
 **8.Delete of Files Older than 1 Month:** In this module the System will delete all the files older than 1 month and if incase no such File exists then it will display a message "All files are New".

![](/images/Capture9.JPG)

 **9.Exit:** With this module the user can Exit through the System loop.

![](/images/Capture10.JPG)



</br></br>
 Licensed under the [MIT License](LICENSE).
