# File format

## The main file

### Pages
The main database file consists of one or more pages. Currently, the size of a page is set to be 4096 bytes, however this may be changed in the future to be user-selected to any power of 2 from an interval, probably between 512 and 32768 bytes.
The pages are numbered from 1, with the maximum page number being 2^16-1 (probably).
Any page is exactly one of these types:
* A header page
* A B-tree page
    * A B-tree interior page
    * A B-tree leaf page
* A table data page
* A free page
* A table definition page

In future, we also expect these two types of pages to occur:
* A payload overflow page
* A pointer map page

The first page of the database is **always** a header page, and the second page of the database is **always** a b-tree page for an unnamed table of all (other) tables. It is also the only table that doesn't have its table definition page, as it is defined implicitly in this document.

### Database header

The first page consists only of the database header, with the rest of the page being empty (filled with '\0').

| Offset | Length | Description |
|--------|--------|-------------|
| 0      | 16     | The magic string "ZimaDB file ver1"
| 30     | 2 (4?) | The first page in a free page linked list. If the list is empty, the value is 0.


### Free pages
A page in the database file may not be in active use, as the data stored there may have been deleted. These pages are called free pages and are stored in a linked list.


### B-tree pages



## Rollback journal