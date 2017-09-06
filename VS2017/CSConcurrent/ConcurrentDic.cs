using System.Collections.Concurrent;
using System.Collections.Generic;

namespace CSConcurrent
{
    public class ConcurrentDic<T>
    {
        private readonly static ConcurrentDictionary<string, T> _dic = new ConcurrentDictionary<string, T>();

        public void Add(string key, T value)
        {
            _dic.TryAdd(key, value);
        }

        public bool ContainsKey(string key)
        {
            return _dic.ContainsKey(key);
        }

        public ICollection<string> Keys
        {
            get { return _dic.Keys; }
        }

        public bool Remove(string key)
        {
            T val;
            return _dic.TryRemove(key, out val);
        }

        public bool TryGetValue(string key, out T value)
        {
            return _dic.TryGetValue(key, out value);
        }

        public ICollection<T> Values
        {
            get { return _dic.Values; }
        }

        public T this[string key]
        {
            get
            {
                return _dic[key];
            }
            set
            {
                _dic[key] = value;
            }
        }
    }
}