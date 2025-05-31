// memory_card_groups.h
//
// WARNING: This file embeds dictionary data directly into the header.
// This approach is used to fulfill a specific request but is generally NOT
// recommended for large datasets or for headers included in many .c files.
// Each .c file that includes this header will get its own copy of this data,
// which can increase compilation time and executable size.
//
// For standard practice, data definitions should be in a .c file,
// with only declarations in the .h file.

#ifndef VMC_GROUPS_H
#define VMC_GROUPS_H

#include <stddef.h> // Required for size_t

// Structure to hold a single Memory Card Group and its associated Title IDs
typedef struct
{
    const char *groupId;   // The group ID string (e.g., "XEBP_100.01")
    const char **titleIds; // Pointer to an array of title ID strings
    size_t titleCount;     // Number of title IDs in the 'titleIds' array
} MemoryCardGroup;

/**
 * @brief Finds the Group ID associated with a given Title ID.
 *
 * This function iterates through all embedded memory card groups.
 * If the provided Title ID is found within any group's list of Title IDs,
 * the Group ID for that group is returned.
 * If the Title ID is not found in any group, the original Title ID
 * passed as a parameter is returned.
 *
 * @param titleId A null-terminated string representing the Title ID to search for.
 * @return A const char* pointer to the Group ID string if found,
 * otherwise, a const char* pointer to the original titleId parameter.
 */

const char *getGroupIdForTitleId(const char *titleId);
#endif // VMC_GROUPS_H
