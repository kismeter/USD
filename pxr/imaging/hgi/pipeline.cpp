//
// Copyright 2020 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#include "pxr/imaging/hgi/pipeline.h"

PXR_NAMESPACE_OPEN_SCOPE

HgiPipeline::HgiPipeline(HgiPipelineDesc const& desc)
    : _descriptor(desc)
{
}

HgiPipeline::~HgiPipeline() = default;

HgiPipelineDesc const&
HgiPipeline::GetDescriptor() const
{
    return _descriptor;
}

HgiMultiSampleState::HgiMultiSampleState()
    : alphaToCoverageEnable(false)
{
}

bool operator==(
    const HgiMultiSampleState& lhs,
    const HgiMultiSampleState& rhs)
{
    return lhs.alphaToCoverageEnable == rhs.alphaToCoverageEnable;
}

bool operator!=(
    const HgiMultiSampleState& lhs,
    const HgiMultiSampleState& rhs)
{
    return !(lhs == rhs);
}

HgiRasterizationState::HgiRasterizationState()
    : polygonMode(HgiPolygonModeFill)
    , lineWidth(1.0f)
    , cullMode(HgiCullModeBack)
    , winding(HgiWindingCounterClockwise)
    , rasterizerEnabled(true)
{
}

bool operator==(
    const HgiRasterizationState& lhs,
    const HgiRasterizationState& rhs)
{
    return lhs.polygonMode == rhs.polygonMode &&
           lhs.lineWidth == rhs.lineWidth &&
           lhs.cullMode == rhs.cullMode &&
           lhs.winding == rhs.winding &&
           lhs.rasterizerEnabled == rhs.rasterizerEnabled;
}

bool operator!=(
    const HgiRasterizationState& lhs,
    const HgiRasterizationState& rhs)
{
    return !(lhs == rhs);
}

HgiDepthStencilState::HgiDepthStencilState()
    : depthTestEnabled(true)
    , depthWriteEnabled(true)
    , depthCompareFn(HgiCompareFunctionLess)
    , stencilTestEnabled(false)
{
}

bool operator==(
    const HgiDepthStencilState& lhs,
    const HgiDepthStencilState& rhs)
{
    return lhs.depthTestEnabled == rhs.depthTestEnabled &&
           lhs.depthWriteEnabled == rhs.depthWriteEnabled &&
           lhs.depthCompareFn == rhs.depthCompareFn &&
           lhs.stencilTestEnabled == rhs.stencilTestEnabled;
}

bool operator!=(
    const HgiDepthStencilState& lhs,
    const HgiDepthStencilState& rhs)
{
    return !(lhs == rhs);
}

HgiPipelineDesc::HgiPipelineDesc()
    : pipelineType(HgiPipelineTypeGraphics)
    , shaderProgram()
    , depthState()
{
}

bool operator==(
    const HgiPipelineDesc& lhs,
    const HgiPipelineDesc& rhs)
{
    return lhs.debugName == rhs.debugName &&
           lhs.pipelineType == rhs.pipelineType &&
           lhs.resourceBindings == rhs.resourceBindings &&
           lhs.shaderProgram == rhs.shaderProgram &&
           lhs.depthState == rhs.depthState &&
           lhs.multiSampleState == rhs.multiSampleState &&
           lhs.rasterizationState == rhs.rasterizationState &&
           lhs.vertexBuffers == rhs.vertexBuffers &&
           lhs.colorAttachmentDescs == rhs.colorAttachmentDescs &&
           lhs.depthAttachmentDesc == rhs.depthAttachmentDesc;
}

bool operator!=(
    const HgiPipelineDesc& lhs,
    const HgiPipelineDesc& rhs)
{
    return !(lhs == rhs);
}

HgiVertexAttributeDesc::HgiVertexAttributeDesc()
    : format(HgiFormatFloat32Vec4)
    , offset(0)
    , shaderBindLocation(0)
{
}

bool operator==(
    const HgiVertexAttributeDesc& lhs,
    const HgiVertexAttributeDesc& rhs)
{
    return lhs.format == rhs.format &&
           lhs.offset == rhs.offset &&
           lhs.shaderBindLocation == rhs.shaderBindLocation;
}

bool operator!=(
    const HgiVertexAttributeDesc& lhs,
    const HgiVertexAttributeDesc& rhs)
{
    return !(lhs == rhs);
}

HgiVertexBufferDesc::HgiVertexBufferDesc()
    : bindingIndex(0)
    , vertexStride(0)
{
}

bool operator==(
    const HgiVertexBufferDesc& lhs,
    const HgiVertexBufferDesc& rhs)
{
    return lhs.bindingIndex == rhs.bindingIndex &&
           lhs.vertexAttributes == rhs.vertexAttributes &&
           lhs.vertexStride == rhs.vertexStride;
}

bool operator!=(
    const HgiVertexBufferDesc& lhs,
    const HgiVertexBufferDesc& rhs)
{
    return !(lhs == rhs);
}

PXR_NAMESPACE_CLOSE_SCOPE
