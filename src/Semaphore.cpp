//
// Created by William Daughtridge on 7/12/20.
//

#include "Semaphore.h"

int RVK::Semaphore::CreateSemaphore()
{
    VkSemaphoreCreateInfo semaphoreCreateInfo;
    semaphoreCreateInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
    semaphoreCreateInfo.pNext = VK_NULL_HANDLE;
    semaphoreCreateInfo.flags = 0;

    return vkCreateSemaphore(m_pLogicalDevice->GetDevice(), &semaphoreCreateInfo, nullptr, &m_semaphore);
}