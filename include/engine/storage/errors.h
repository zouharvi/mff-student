#include <string>

#ifndef ERRORS_H
#define ERRORS_H

const std::string ERROR_MESSAGES[] = {
    "An unknown error happened.",
    "An internal error occurred.",
    "No open file to write to.",
    "The requested insert has no primary key.",
    "I/O error.",

};

enum class ErrorId {
    unknown_error,
    received_nullptr,
    no_file_open,
    no_primary_key_insert,
    io_error,
};

std::string error_msg(ErrorId err_id);


#endif