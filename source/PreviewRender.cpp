#include "texlab/PreviewRender.h"
#include "texlab/Evaluator.h"

#include <unirender/DrawState.h>
#include <painting3/RenderSystem.h>
#include <node0/SceneNode.h>
#include <node3/RenderSystem.h>

namespace texlab
{

PreviewRender::PreviewRender(const pt3::Viewport& vp,
                             const sm::mat4& cam_mat)
    : m_vp(vp)
    , m_cam_mat(cam_mat)
{
}

void PreviewRender::DrawNode(const ur::Device& dev, ur::Context& ctx,
                             const pt0::RenderContext& rc, const n0::SceneNode& node) const
{
    pt3::RenderParams rp;
    rp.painter  = &m_pt;
    rp.viewport = &m_vp;
    rp.cam_mat  = &m_cam_mat;

    ur::DrawState ds;
    n3::RenderSystem::Draw(dev, ctx, ds, node, rp, rc);
}

}