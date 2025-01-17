/*
 * Copyright (C) 2016 E.S.R.Labs
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mindroid/lang/Class.h"

namespace mindroid
{

pthread_mutex_t Classes::sMutex = PTHREAD_MUTEX_INITIALIZER;
Classes* Classes::sInstance = nullptr;

void Classes::put(const sp<String>& name, Factory* factory)
{
    pthread_mutex_lock(&sMutex);
    mClasses->put(name, factory);
    pthread_mutex_unlock(&sMutex);
}

Factory* Classes::get(const sp<String>& name)
{
    pthread_mutex_lock(&sMutex);
    Factory* factory = mClasses->get(name);
    pthread_mutex_unlock(&sMutex);
    return factory;
}

Classes* Classes::getInstance()
{
    pthread_mutex_lock(&sMutex);

    if (sInstance == nullptr) {
        sInstance = new Classes();
    }

    pthread_mutex_unlock(&sMutex);
    return sInstance;
}

} /* namespace mindroid */
