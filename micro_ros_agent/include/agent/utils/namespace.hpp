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

#ifndef UROS_AGENT_UTILS_NAMESPACE_HPP_
#define UROS_AGENT_UTILS_NAMESPACE_HPP_

#include <string>

namespace uros {
namespace agent {
namespace utils {

class Namespace
{
private:
    /**
     * @brief   Default constructor. Creating instances of this class is not allowed.
     */
    Namespace() = default;

    /**
     * @brief   Default destructor.
     */
    ~Namespace() = default;

public:
    /**
     * @brief   Check if a topic name is a ROS topic (starts with rq/, rt/, or rr/).
     * @param   topic_name Topic name to check.
     * @returns True if the topic is a ROS topic with service prefixes, false otherwise.
     */
    static bool is_ros_topic(
            const std::string& topic_name);

    /**
     * @brief   Check if a topic name is a topic that should have global namespace (eg. tf, rosout).
     * @param   topic_name Topic name to check.
     * @returns True if the topic is a global topic, false otherwise.
     */
    static bool is_global_topic(
            const std::string& topic_name);

    /**
     * @brief   Apply namespace to a ROS topic.
     * @param   topic_name Original topic name.
     * @param   namespace_prefix Namespace to apply (should start with /).
     * @returns The topic name with namespace applied.
     */
    static std::string apply_namespace_to_topic(
            const std::string& topic_name,
            const std::string& namespace_prefix);

    /**
     * @brief   Apply namespace to a ROS node.
     * @param   node_name Original node name.
     * @param   namespace_prefix Namespace to apply (should start with /).
     * @returns The node name with namespace applied.
     */
    static std::string apply_namespace_to_node(
            const std::string& node_namespace,
            const std::string& namespace_prefix);
};

}  // namespace utils
}  // namespace agent
}  // namespace uros

#endif  // UROS_AGENT_UTILS_NAMESPACE_HPP_
