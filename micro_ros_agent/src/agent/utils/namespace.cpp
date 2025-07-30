// MIT License
// 
// Copyright (c) 2020-2025 Fictionlab sp. z o.o.
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef UROS_AGENT_UTILS_NAMESPACE_CPP_
#define UROS_AGENT_UTILS_NAMESPACE_CPP_

#include <agent/utils/namespace.hpp>

namespace uros {
namespace agent {
namespace utils {

bool Namespace::is_ros_topic(
        const std::string& topic_name)
{
    return (topic_name.length() >= 3 &&
            (topic_name.substr(0, 3) == "rq/" || 
             topic_name.substr(0, 3) == "rt/" || 
             topic_name.substr(0, 3) == "rr/"));
}

bool Namespace::is_global_topic(
        const std::string& topic_name)
{
    return (topic_name == "/tf" || 
            topic_name == "/tf_static" || 
            topic_name == "/diagnostics" || 
            topic_name == "/rosout" || 
            topic_name == "/parameter_events");
}

std::string Namespace::apply_namespace_to_topic(
        const std::string& topic_name,
        const std::string& namespace_prefix)
{
    if (namespace_prefix.empty() || 
        namespace_prefix == "/" || 
        !is_ros_topic(topic_name) || 
        is_global_topic(topic_name.substr(2)))
    {
        return topic_name;
    }

    std::string service_prefix = topic_name.substr(0, 2);
    std::string remaining_topic = topic_name.substr(2);
                
    return service_prefix + namespace_prefix + remaining_topic;
}

std::string Namespace::apply_namespace_to_node(
        const std::string& node_namespace,
        const std::string& namespace_prefix)
{
        if (node_namespace == "/")
        {
            return namespace_prefix;
        }
        else
        {
            return namespace_prefix + node_namespace;
        }
}

}  // namespace utils
}  // namespace agent
}  // namespace uros

#endif  // UROS_AGENT_UTILS_NAMESPACE_CPP_
