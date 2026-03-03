#include "ConstantBuffer.h"

namespace me3d
{
  ConstantBuffer::ConstantBuffer()
    : commitNeeded_b(true)
  {

  }

  ConstantBuffer::~ConstantBuffer()
  {

  }

  void ConstantBuffer::signalCommitNeeded_v()
  {
    commitNeeded_b = true;
  }

} // namespace me3d