#ifndef PCP_JSON_PARSER_HPP
#define PCP_JSON_PARSER_HPP

#include <string>

namespace pcp {

// Minimal JSON parser — extracts a string value for a given key
// Handles objects like {"key": "value"} or {"key": 123}
std::string parseJsonStringValue(const std::string& json, const std::string& key);

} // namespace pcp

#endif // PCP_JSON_PARSER_HPP
