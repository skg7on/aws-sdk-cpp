﻿/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#pragma once
#include <aws/ec2/EC2_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/ec2/model/ResponseMetadata.h>
#include <aws/ec2/model/SpotPrice.h>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Xml
{
  class XmlDocument;
} // namespace Xml
} // namespace Utils
namespace EC2
{
namespace Model
{
  /**
   * <p>Contains the output of DescribeSpotPriceHistory.</p>
   */
  class AWS_EC2_API DescribeSpotPriceHistoryResponse
  {
  public:
    DescribeSpotPriceHistoryResponse();
    DescribeSpotPriceHistoryResponse(const AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);
    DescribeSpotPriceHistoryResponse& operator=(const AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);

    /**
     * <p>The historical Spot prices.</p>
     */
    inline const Aws::Vector<SpotPrice>& GetSpotPriceHistory() const{ return m_spotPriceHistory; }

    /**
     * <p>The historical Spot prices.</p>
     */
    inline void SetSpotPriceHistory(const Aws::Vector<SpotPrice>& value) { m_spotPriceHistory = value; }

    /**
     * <p>The historical Spot prices.</p>
     */
    inline void SetSpotPriceHistory(Aws::Vector<SpotPrice>&& value) { m_spotPriceHistory = value; }

    /**
     * <p>The historical Spot prices.</p>
     */
    inline DescribeSpotPriceHistoryResponse& WithSpotPriceHistory(const Aws::Vector<SpotPrice>& value) { SetSpotPriceHistory(value); return *this;}

    /**
     * <p>The historical Spot prices.</p>
     */
    inline DescribeSpotPriceHistoryResponse& WithSpotPriceHistory(Aws::Vector<SpotPrice>&& value) { SetSpotPriceHistory(value); return *this;}

    /**
     * <p>The historical Spot prices.</p>
     */
    inline DescribeSpotPriceHistoryResponse& AddSpotPriceHistory(const SpotPrice& value) { m_spotPriceHistory.push_back(value); return *this; }

    /**
     * <p>The historical Spot prices.</p>
     */
    inline DescribeSpotPriceHistoryResponse& AddSpotPriceHistory(SpotPrice&& value) { m_spotPriceHistory.push_back(value); return *this; }

    /**
     * <p>The token required to retrieve the next set of results. This value is
     * <code>null</code> when there are no more results to return.</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>The token required to retrieve the next set of results. This value is
     * <code>null</code> when there are no more results to return.</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextToken = value; }

    /**
     * <p>The token required to retrieve the next set of results. This value is
     * <code>null</code> when there are no more results to return.</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextToken = value; }

    /**
     * <p>The token required to retrieve the next set of results. This value is
     * <code>null</code> when there are no more results to return.</p>
     */
    inline void SetNextToken(const char* value) { m_nextToken.assign(value); }

    /**
     * <p>The token required to retrieve the next set of results. This value is
     * <code>null</code> when there are no more results to return.</p>
     */
    inline DescribeSpotPriceHistoryResponse& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>The token required to retrieve the next set of results. This value is
     * <code>null</code> when there are no more results to return.</p>
     */
    inline DescribeSpotPriceHistoryResponse& WithNextToken(Aws::String&& value) { SetNextToken(value); return *this;}

    /**
     * <p>The token required to retrieve the next set of results. This value is
     * <code>null</code> when there are no more results to return.</p>
     */
    inline DescribeSpotPriceHistoryResponse& WithNextToken(const char* value) { SetNextToken(value); return *this;}

    
    inline const ResponseMetadata& GetResponseMetadata() const{ return m_responseMetadata; }

    
    inline void SetResponseMetadata(const ResponseMetadata& value) { m_responseMetadata = value; }

    
    inline void SetResponseMetadata(ResponseMetadata&& value) { m_responseMetadata = value; }

    
    inline DescribeSpotPriceHistoryResponse& WithResponseMetadata(const ResponseMetadata& value) { SetResponseMetadata(value); return *this;}

    
    inline DescribeSpotPriceHistoryResponse& WithResponseMetadata(ResponseMetadata&& value) { SetResponseMetadata(value); return *this;}

  private:
    Aws::Vector<SpotPrice> m_spotPriceHistory;
    Aws::String m_nextToken;
    ResponseMetadata m_responseMetadata;
  };

} // namespace Model
} // namespace EC2
} // namespace Aws