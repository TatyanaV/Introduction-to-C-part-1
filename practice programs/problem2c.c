    #string line;
    getline(ins, line);
    istringstream convert(line);
    // extract first name
    if (! (convert >> line) ) {
    return;
    }
    the_name.fName = line;
    // extract middle name
    if (! (convert >> line) ) {
    return;
    }
    the_name.mName = line;
    // extract last name
    if (! (convert >> line) ) {
    // if there is no last name, previous must have been middle
    the_name.lName = the_name.mName;
    the_name.mName = "";
    }
    else {
    the_name.lName = line;
    }
