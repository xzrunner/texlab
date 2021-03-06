#pragma once

#include "texlab/NodePreview.h"

#include <blueprint/Node.h>

#include <texgraph/Node.h>

namespace texlab
{

class Node : public bp::Node
{
public:
    Node(const std::string& title, bool props = false);
    Node(const Node& node);
    Node& operator = (const Node& node);
    virtual ~Node();

    virtual void Draw(const ur::Device& dev, ur::Context& ctx,
        const n2::RenderParams& rp) const override;

    auto& GetName() const { return m_name; }
    void  SetName(const std::string& name) { m_name = name; }

    void UpdatePins(const texgraph::Node& node);

    auto& GetPreview() const { return m_preview; }

protected:
    struct PinDesc
    {
        bool operator == (const PinDesc& desc) const {
            return type == desc.type && name == desc.name;
        }

        int         type;
        std::string name;
    };

public:
    static const char* STR_PROP_DISPLAY;

protected:
    void InitPins(const std::vector<PinDesc>& input,
        const std::vector<PinDesc>& output);
    void InitPins(const std::string& name);

private:
    void InitPinsImpl(const std::vector<PinDesc>& pins,
        bool is_input);

    static void PortBack2Front(std::vector<PinDesc>& dst,
        const std::vector<texgraph::Node::Port>& src);

private:
    std::string m_name;

    NodePreview m_preview;

    RTTR_ENABLE(bp::Node)

}; // Node

}