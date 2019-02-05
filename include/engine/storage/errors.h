#include <string>

#ifndef ERRORS_H
#define ERRORS_H

const std::string ERROR_MESSAGES[] = {
    "An unknown error happened.",
    "An internal error occurred.",
    "No open file to write to.",
    "The requested insert has no primary key.",
    "I/O error.",
    "The table does not exist.",
    "This command is not implemented for provisional files.",
    "A column doesn't exist in the table.",
};

enum class ErrorId
{
    unknown_error,
    received_nullptr,
    no_file_open,
    no_primary_key_insert,
    io_error,
    table_does_not_exist,
    not_implemented_provisional,
    inserting_nonexistent_column,
};

std::string error_msg(ErrorId err_id);

#endif