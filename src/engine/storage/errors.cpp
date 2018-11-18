#include "storage/errors.h"

std::string error_msg(ErrorId err_id)
{
    return "Error: ID " + std::to_string(static_cast<int>(err_id)) + ":" + ERROR_MESSAGES[static_cast<int>(err_id)];
}