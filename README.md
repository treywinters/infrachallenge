# infrachallenge

For this problem, I am tasked with parsing through a text file and creating normal and hash files for each line of text in the original file, I am then required to arrange these files in order of file size and remove the duplicate line of text from the original file. 

The first step was to make a loop that created new files from the original given file using iostreams and create the accompanying hash files using the hash function. It was here that I decide that the best way to get easy access to each file and its file size, was to create a file name / file size pair. By doing this, I was able to insert the newly created files in order of their file size as they were being made. Once I had my completed list of sorted file names, I searched through it to find the duplicate file that would be taken out in the final step. In recreating the final “loomings-clean.txt”, all I did was go through my original list of unsorted file names and add each one to the new file except for the duplicate.

With that, the challenge is complete, and by running the “run.sh” command, you should have 16 text files 16 hash files and one clean version of loomings created.
