void menu() { 
	char *op = malloc(MAXSIZEOP)

	do
		fgets(&op, MAXSIZEOP, stdin)

		if !strcmp(op, "insert")
			// <key>, <info1>, <info2> ...
			insertData(nomeMet, name.reg)
		
		else if !strcmp(op, "index") 
			// creates a binary file called name.idx
			createIndex(nomeMet, name.reg)
			 |	// sort according to keys
			 ->	sortIndex(name.idx)

		else if !strcmp(op, "search")	
			// realize a binary search 
			if (!existIndex) createIndex(nameMet, name.reg)
			unsigned int offset = serchByKey(name.idx)
			// print a list with data, using ftell e fseek
			// <>: <>\n
			// <>: <>\n 
			//   ...
			// <>: <>\n\n 
			if (offset) printData(name.reg, offset)


	while !strcmp(op, "exit")

	return 0
}	