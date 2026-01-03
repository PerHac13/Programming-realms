package main

import (
	"bufio"
	"os"
)

/*
* File related operations
* example.txt is sample file in the same directory

 */

func main() {
	// Create a file
	file, err := os.Create("example.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()
	
	// Write to the file
	_, err = file.WriteString("Hello, World!\n")
	if err != nil {
		panic(err)
	}

	_, err = file.WriteString("This is a sample file.\n")
	if err != nil {
		panic(err)
	}

	// Read from the file
	data, err := os.ReadFile("example.txt")
	if err != nil {
		panic(err)
	}
	println(string(data))

	// Delete the file
	err = os.Remove("example.txt")
	if err != nil {
		panic(err)
	}

	// Open a file
	f, err := os.Open("input.txt")
	if err != nil {
		panic(err)
	}
	defer f.Close()

	// Get file info
	fileInfo, err := f.Stat()
	if err != nil {
		panic(err)
	}
	println("File Name:", fileInfo.Name())
	println("File Size:", fileInfo.Size())
	println("Is Directory:", fileInfo.IsDir())
	println("Modification Time:", fileInfo.ModTime().String())
	println("File Mode:", fileInfo.Mode().String())

	// Rename a file
	// err = os.Rename("input.txt", "renamed_input.txt")
	// if err != nil {
	// 	panic(err)
	// }

	// Change file permissions
	// err = os.Chmod("renamed_input.txt", 0644)
	// if err != nil {
	// 	panic(err)
	// }

	// Create a directory
	err = os.Mkdir("sample_dir", 0755)	

	if err != nil {
		panic(err)
	}

	// Remove a directory
	err = os.Remove("sample_dir")
	if err != nil {
		panic(err)
	}

	// Get current working directory
	cwd, err := os.Getwd()
	if err != nil {
		panic(err)
	}
	println("Current Working Directory:", cwd)

	// Change current working directory
	// err = os.Chdir("..")
	// if err != nil {
	// 	panic(err)
	// }

	// List files in a directory
	files, err := os.ReadDir("../")
	if err != nil {
		panic(err)
	}
	println("Files in current directory:")
	for _, file := range files {
		println(" -", file.Name())
	}

	// stream file read/write using os.File
	// Open file for reading and writing

	sourceFile, err := os.Open("input.txt")
	if err != nil {
		panic(err)
	}
	defer sourceFile.Close()

	destFile, err := os.Create("output.txt")
	if err != nil {
		panic(err)
	}
	defer destFile.Close()

	reader := bufio.NewReader(sourceFile)
	writer := bufio.NewWriter(destFile)

	for {
		b, err := reader.ReadByte()
		if err != nil {
			if err.Error() != "EOF" {
				panic(err)
			}
			break
		}
		err = writer.WriteByte(b)
		if err != nil {
			panic(err)
		}
	}

	writer.Flush()

	// println("")

	
}